# Qt library practice(pronounced as "cute")

## Dependencies
```
sudo apt-get install \
qtcreator \
qt5-default \
libcurl4-openssl-dev
```

## Build
```
qt_ws$ mkdir build
qt_ws$ cd build
qt_ws/build$ cmake ..
qt_ws/build$ cmake --build .
```

## Run
```
qt_ws/build$ ./qt
```

## Development notes
- An email can be sent through ubuntu terminal.
  - [https://stackoverflow.com/questions/70730838/how-to-send-email-with-gmail-using-curl-in-c](https://stackoverflow.com/questions/70730838/how-to-send-email-with-gmail-using-curl-in-c)
- An email will be sent via the google SMTP server. A google account with app password are needed. [You need to set](https://support.google.com/mail/answer/185833?hl=en)
  1. 2-Step Verification 
  2. App password
   
  The App password will be used for the curl command.