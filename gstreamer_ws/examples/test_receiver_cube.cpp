//basic-tutorial-3.c
#include <gst/gst.h>
#include <GLFW/glfw3.h>

#include <gst/gl/gl.h>
#include <thread>
#include <iostream>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <netdb.h>

/* Structure to contain all our information, so we can pass it to callbacks */
typedef struct _CustomData {
  GstElement *pipeline;
  GstElement *source;
  GstElement *convert;
  GstElement *sink;
} CustomData;

void funccc()
{
    g_print ("chat_server on\n");
    char *serverIp = "127.0.0.1";
    int port = 8090;
    char msg[1500];
    //setup a socket and connection tools
    struct hostent* host = gethostbyname(serverIp);
    sockaddr_in sendSockAddr;
    bzero((char*)&sendSockAddr, sizeof(sendSockAddr));
    sendSockAddr.sin_family = AF_INET;
    sendSockAddr.sin_addr.s_addr = inet_addr(inet_ntoa(*(struct in_addr*)*host->h_addr_list));
    sendSockAddr.sin_port = htons(port);
    int clientSd = socket(AF_INET, SOCK_STREAM, 0);
    //try to connect...
    int status = connect(clientSd, (sockaddr*) &sendSockAddr, sizeof(sendSockAddr));
    if(status < 0)
    {
        std::cout<<"Error connecting to socket!"<<std::endl;
    }
    std::cout << "Connected to the server!" << std::endl;
    int bytesWritten = 0;
    while(1)
    {
        std::cout << ">";
        std::string data;
        getline(std::cin, data);
        memset(&msg, 0, sizeof(msg));//clear the buffer
        strcpy(msg, data.c_str());
        if(data == "exit")
        {
            send(clientSd, (char*)&msg, strlen(msg), 0);
            break;
        }
        bytesWritten += send(clientSd, (char*)&msg, strlen(msg), 0);
    }
    close(clientSd);
}

static gboolean bus_call (GstBus *bus, GstMessage *msg, gpointer data)
{
    GMainLoop *loop = (GMainLoop*)data;

    switch (GST_MESSAGE_TYPE (msg))
    {
        case GST_MESSAGE_EOS:
              g_print ("End-of-stream\n");
              g_main_loop_quit (loop);
              break;
        case GST_MESSAGE_ERROR:
          {
              gchar *debug = NULL;
              GError *err = NULL;

              gst_message_parse_error (msg, &err, &debug);

              g_print ("Error: %s\n", err->message);
              g_error_free (err);

              if (debug)
              {
                  g_print ("Debug deails: %s\n", debug);
                  g_free (debug);
              }

              g_main_loop_quit (loop);
              break;
          }
        default:
          break;
    }

    return TRUE;
}

//client reshape callback
static gboolean reshapeCallback (void *gl_sink, void *context, GLuint width, GLuint height, gpointer data)
{
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);

    return TRUE;
}

//client draw callback
static gboolean drawCallback (GstElement * gl_sink, GstGLContext *context, GstSample * sample, gpointer data)
{
    static GLfloat xrot = 0;
    static GLfloat yrot = 0;
    static GLfloat zrot = 0;

    GstVideoFrame v_frame;
    GstVideoInfo v_info;
    guint texture = 0;
    GstBuffer *buf = gst_sample_get_buffer (sample);
    GstCaps *caps = gst_sample_get_caps (sample);

    gst_video_info_from_caps (&v_info, caps);

    if (!gst_video_frame_map (&v_frame, &v_info, buf, (GstMapFlags) (GST_MAP_READ | GST_MAP_GL))) {
      g_warning ("Failed to map the video buffer");
      return TRUE;
    }

    texture = *(guint *) v_frame.data[0];

    glEnable (GL_TEXTURE_2D);
    glBindTexture (GL_TEXTURE_2D, texture);
    glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexEnvi (GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    /* invert the y-axis to get the front face the correct way up */
    glScalef (1.0f, -1.0f, 1.0f);

    // glColor3f(1.0f, 0.0f, 0.0f); // Red

    // start darwing
    glBegin(GL_QUADS);
      glTexCoord2f(1.0f, 0.0f); glVertex2f(-0.5f, -0.5f);    // bottom left
      glTexCoord2f(0.0f, 0.0f); glVertex2f( 0.5f, -0.5f);    // bottom right
      glTexCoord2f(0.0f, 1.0f); glVertex2f( 0.5f,  0.5f);    // top right
      glTexCoord2f(1.0f, 1.0f); glVertex2f(-0.5f,  0.5f);    // top left
    glEnd();

    gst_video_frame_unmap (&v_frame);

    glDisable (GL_TEXTURE_2D);
    // glEnable(GL_DEPTH_TEST);

    // glEnable (GL_TEXTURE_2D);
    // glBindTexture (GL_TEXTURE_2D, texture);
    // glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    // glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    // glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    // glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    // glTexEnvi (GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);

    // glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    // glMatrixMode(GL_MODELVIEW);
    // glLoadIdentity();

    // /* invert the y-axis to get the front face the correct way up */
    // glScalef (0.5f, -0.5f, 0.5f);

    // glRotatef(xrot,1.0f,0.0f,0.0f);
    // glRotatef(yrot,0.0f,1.0f,0.0f);
    // glRotatef(zrot,0.0f,0.0f,1.0f);

    // glBegin(GL_QUADS);
	//       // Front Face
	//       glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f,  1.0f);
	//       glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f,  1.0f);
	//       glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f,  1.0f,  1.0f);
	//       glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f,  1.0f,  1.0f);
	//       // Back Face
	//       glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
	//       glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,  1.0f, -1.0f);
	//       glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f,  1.0f, -1.0f);
	//       glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, -1.0f, -1.0f);
	//       // Top Face
	//       glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f,  1.0f, -1.0f);
	//       glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f,  1.0f,  1.0f);
	//       glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f,  1.0f,  1.0f);
	//       glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f,  1.0f, -1.0f);
	//       // Bottom Face
	//       glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
	//       glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f, -1.0f);
	//       glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f, -1.0f,  1.0f);
	//       glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, -1.0f,  1.0f);
	//       // Right face
	//       glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f, -1.0f);
	//       glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f,  1.0f, -1.0f);
	//       glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f,  1.0f,  1.0f);
	//       glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, -1.0f,  1.0f);
	//       // Left Face
	//       glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
	//       glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f,  1.0f);
	//       glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,  1.0f,  1.0f);
	//       glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f,  1.0f, -1.0f);
    // glEnd();

    // gst_video_frame_unmap (&v_frame);

    // xrot+=0.3f;
    // yrot+=0.2f;
    // zrot+=0.4f;

    // glDisable (GL_DEPTH_TEST);
    // glDisable (GL_TEXTURE_2D);

    return TRUE;
}

// pipeline = gst_parse_launch ("rtspsrc location=rtsp://127.0.0.1:8554/test latency=100 ! queue ! rtph264depay ! h264parse ! avdec_h264 ! videoconvert ! gtksink", NULL);

int main(int argc, char *argv[]) {
  CustomData data;
  GstBus *bus;
  GstStateChangeReturn ret;
    GMainLoop *loop;

    g_setenv ("GST_GL_API", "opengl", FALSE);

  /* Initialize GStreamer */
  gst_init (&argc, &argv);
    loop = g_main_loop_new (NULL, FALSE);

  /* Create the empty pipeline */
  data.pipeline = gst_pipeline_new ("test-pipeline");

  /* Listen to the bus */
    /* watch for messages on the pipeline's bus (note that this will only
     * work like this when a GLib main loop is running) */
    bus = gst_pipeline_get_bus (GST_PIPELINE (data.pipeline));
    gst_bus_add_watch (bus, bus_call, loop);
    gst_object_unref (bus);

  /* Create the elements */
//   data.source = gst_element_factory_make ("uridecodebin", "source");
//   data.convert = gst_element_factory_make ("videoconvert", "convert");
  data.source = gst_element_factory_make ("videotestsrc", "source");
  data.sink = gst_element_factory_make ("glimagesink", "sink");

  if (!data.pipeline || !data.source/*  || !data.convert */ || !data.sink) {
    g_printerr ("Not all elements could be created.\n");
    return -1;
  }

    /* change video source caps */
    GstCaps *caps = gst_caps_new_simple("video/x-raw",
                                        "format", G_TYPE_STRING, "RGB",
                                        "width", G_TYPE_INT, 1280,
                                        "height", G_TYPE_INT, 1024,
                                        "framerate", GST_TYPE_FRACTION, 15, 1,
                                        NULL) ;

    /* configure elements */
    g_object_set(G_OBJECT(data.source), "num-buffers", 400, NULL);
    g_signal_connect(G_OBJECT(data.sink), "client-reshape", G_CALLBACK (reshapeCallback), NULL);
    g_signal_connect(G_OBJECT(data.sink), "client-draw", G_CALLBACK (drawCallback), NULL);

  /* add elements */
  gst_bin_add_many (GST_BIN (data.pipeline), data.source,/*  data.convert, */ data.sink, NULL);
//   if (!gst_element_link (data.convert, data.sink)) {
//     g_printerr ("Elements could not be linked.\n");
//     gst_object_unref (data.pipeline);
//     return -1;
//   }

    /* link elements */
    gboolean link_ok = gst_element_link_filtered(data.source, data.sink, caps) ;
    gst_caps_unref(caps) ;
    if(!link_ok)
    {
        g_warning("Failed to link videosrc to glimagesink!\n") ;
        return -1 ;
    }

  /* Set the URI to play */
//   g_object_set (data.source, "uri", "rtsp://127.0.0.1:8554/test", NULL);

     /* run */
    ret = gst_element_set_state (data.pipeline, GST_STATE_PLAYING);
    if (ret == GST_STATE_CHANGE_FAILURE)
    {
        g_print ("Failed to start up pipeline!\n");

        /* check if there is an error message with details on the bus */
        GstMessage* msg = gst_bus_poll (bus, GST_MESSAGE_ERROR, 0);
        if (msg)
        {
          GError *err = NULL;

          gst_message_parse_error (msg, &err, NULL);
          g_print ("ERROR: %s\n", err->message);
          g_error_free (err);
          gst_message_unref (msg);
        }
        return -1;
    }

    g_main_loop_run (loop);

    /* clean up */
    gst_element_set_state (data.pipeline, GST_STATE_NULL);
    gst_object_unref (data.pipeline);

    return 0;
}
