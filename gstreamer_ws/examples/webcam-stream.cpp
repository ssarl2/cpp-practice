//original name: imagefreeze.cpp
//TO PLAY STREAM: gst-launch-1.0 udpsrc port=9003 caps='application/x-rtp, media=(string)video, clock-rate=(int)90000, payload=(int)96, encoding-name=(string)H264' ! rtph264depay ! queue ! avdec_h264 ! videoconvert ! autovideosink
//https://github.com/alexagv/gst_tests/tree/17f4f07ec4f89d5bfaeb265c08526c2d02e7365c
#include <gst/gst.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

static GMainLoop *loop;
cv::VideoCapture cap;

static void cb_need_data(GstElement *appsrc, guint unused_size, gpointer user_data) {
  static gboolean white = FALSE;
  static GstClockTime timestamp = 0;
  GstBuffer *buffer;
  guint size;
  GstFlowReturn ret;

  // grab cam frame
  cv::Mat image;
  cap.read(image);
  guint8 *data = image.data;
  size = image.cols * image.rows * image.channels();
  buffer = gst_buffer_new_allocate (NULL, size, NULL);

  /* this makes the image black/white */
  //gst_buffer_memset (buffer, 0, white ? 0xff : 0x0, size);
  //white = !white;
  gst_buffer_fill(buffer, 0, data, size);

  GST_BUFFER_PTS (buffer) = timestamp;
  GST_BUFFER_DURATION (buffer) = gst_util_uint64_scale_int (1, GST_SECOND, 120);

  timestamp += GST_BUFFER_DURATION (buffer);

  g_signal_emit_by_name (appsrc, "push-buffer", buffer, &ret);

  if (ret != GST_FLOW_OK) {
    /* something wrong, stop pushing */
    g_main_loop_quit (loop);
  }
}

int main(int argc, char *argv[]) {

  // open cam
  cap.open(0);
  cap.set(CV_CAP_PROP_FRAME_WIDTH, 640);
  cap.set(CV_CAP_PROP_FRAME_HEIGHT, 480);

  GstElement *pipeline, *appsrc, *conv, *videosink, *enc, *parse, *pay, *udpsink, *rtspsink, image;

  /* init GStreamer */
  gst_init (&argc, &argv);
  loop = g_main_loop_new (NULL, FALSE);

  /* setup pipeline */
  pipeline = gst_pipeline_new ("pipeline");
  appsrc = gst_element_factory_make ("appsrc", "source");
  conv = gst_element_factory_make ("videoconvert", "conv");
        enc = gst_element_factory_make ("x264enc", "enc");
        parse = gst_element_factory_make ("h264parse", "parse");
        pay = gst_element_factory_make ("rtph264pay", "pay");
  videosink = gst_element_factory_make ("xvimagesink", "videosink");
        udpsink = gst_element_factory_make ("udpsink", "udpsink");
        rtspsink = gst_element_factory_make ("rtspsink", "rtspsink");

  /* setup */
  g_object_set (G_OBJECT (appsrc), "caps",
      gst_caps_new_simple ("video/x-raw",
        "format", G_TYPE_STRING, "BGR",
        "width", G_TYPE_INT, 640,
        "height", G_TYPE_INT, 480,
        "framerate", GST_TYPE_FRACTION, 15, 1,
        NULL), NULL);

  g_print("TO PLAY STREAM: gst-launch-1.0 udpsrc port=9003 caps='application/x-rtp, media=(string)video, clock-rate=(int)90000, payload=(int)96, encoding-name=(string)H264' ! rtph264depay ! queue ! avdec_h264 ! videoconvert ! autovideosink");
  g_object_set(G_OBJECT(udpsink), "host", "127.0.0.1", "port", 9003, NULL);

  gst_bin_add_many(GST_BIN(pipeline), appsrc, conv, enc, parse, pay, udpsink, NULL);
  gst_element_link_many(appsrc, conv, enc, parse, pay, udpsink, NULL);

  /* setup appsrc */
  g_object_set (G_OBJECT (appsrc),
      "stream-type", 0,
      "format", GST_FORMAT_TIME, NULL);
  g_signal_connect (appsrc, "need-data", G_CALLBACK (cb_need_data), NULL);

  /* play */
  gst_element_set_state (pipeline, GST_STATE_PLAYING);
  g_main_loop_run (loop);

  /* clean up */
  gst_element_set_state (pipeline, GST_STATE_NULL);
  gst_object_unref (GST_OBJECT (pipeline));
  g_main_loop_unref (loop);

  return 0;
}
