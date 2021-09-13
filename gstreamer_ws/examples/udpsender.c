//TEST UDP SENDER, BASED ON HELLOWORLD EXAMPLE
//TO COMPILE: gcc -Wall test-udp-sender.c -o test-udp-sender $(pkg-config --cflags --libs gstreamer-1.0)
//TO PLAY STREAM: gst-launch-1.0 udpsrc port=5004 caps='application/x-rtp, media=(string)video, clock-rate=(int)90000, payload=(int)96, encoding-name=(string)H264' ! rtph264depay ! queue ! avdec_h264 ! videoconvert ! autovideosink
#include <gst/gst.h>
#include <glib.h>

static gboolean
bus_call (GstBus     *bus,
          GstMessage *msg,
          gpointer    data)
{
  GMainLoop *loop = (GMainLoop *) data;

  switch (GST_MESSAGE_TYPE (msg)) {

    case GST_MESSAGE_EOS:
      g_print ("End of stream\n");
      g_main_loop_quit (loop);
      break;

    case GST_MESSAGE_ERROR: {
      gchar  *debug;
      GError *error;
      gst_message_parse_error (msg, &error, &debug);
      g_free (debug);
      g_printerr ("Error: %s\n", error->message);
      g_error_free (error);
      g_main_loop_quit (loop);
      break;
    }
    default:
      break;
  }

  return TRUE;
}

int
main (int   argc,
      char *argv[])
{
  GMainLoop *loop;
  GstElement *pipeline, *source, *encoder, *pay, *sink;
  GstBus *bus;
  guint bus_watch_id;

  /* Initialisation */
  gst_init (&argc, &argv);
  loop = g_main_loop_new (NULL, FALSE);

  /* Create pipeline elements */
  pipeline = gst_pipeline_new ("test-udp-sender");
  source = gst_element_factory_make ("videotestsrc", "test-source");
  encoder = gst_element_factory_make ("x264enc", "h264-encoder");
  pay = gst_element_factory_make ("rtph264pay", "rtp-payloader");
  sink = gst_element_factory_make ("udpsink", "udp-sink");

  if (!pipeline || !source || !encoder || !pay || !sink) {
    g_printerr ("One element could not be created. Exiting.\n");
    return -1;
  }

  /* we set the properties of the pipeline elements */
  g_object_set (G_OBJECT (pay), "name", "pay0", "pt", 96, "config-interval", -1, NULL);
  g_object_set (G_OBJECT (sink), "host" , "127.0.0.1", "port", 5004, NULL);

  /* we add a message handler */
  bus = gst_pipeline_get_bus (GST_PIPELINE (pipeline));
  bus_watch_id = gst_bus_add_watch (bus, bus_call, loop);
  gst_object_unref (bus);

  /* we add all elements into the pipeline */
  gst_bin_add_many (GST_BIN (pipeline), source, encoder, pay, sink, NULL);

  /* we link the elements together */
  gst_element_link_many (source, encoder, pay, sink, NULL);

  /* Set the pipeline to "playing" state*/
  g_print ("Now streaming to localhost at port 5004\n");
  gst_element_set_state (pipeline, GST_STATE_PLAYING);

  /* Iterate */
  g_print ("Running...\n");
  g_main_loop_run (loop);

  /* Out of the main loop, clean up nicely */
  g_print ("Returned, stopping playback\n");
  gst_element_set_state (pipeline, GST_STATE_NULL);

  g_print ("Deleting pipeline\n");
  gst_object_unref (GST_OBJECT (pipeline));
  g_source_remove (bus_watch_id);
  g_main_loop_unref (loop);

  return 0;
}
