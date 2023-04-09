# Qt library practice(pronounced as "cute")
## Purpose
What needs : Qt C++ library  
Help for : myself  
How to achieve : write a lot of useful qt code
## Dependencies
GNU/Linux 20.04
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
### Launch
```
qt_ws/build$ ./qt
```
### Test

## Debug
with gdb(GNU Debugger)  
- After built  
`qt_ws$ cd build`  
`qt_ws/build$ cmake -DCMAKE_BUILD_TYPE=Debug ..` or (better for full debugging)  
`qt_ws/build$ cmake -DCMAKE_BUILD_TYPE=RelWithDebInfo ..` or  
`qt_ws/build$ cmake ..` (because the option is already set in CmakeLists.txt)  
`qt_ws/build$ gdb ./qt` to start the gdb  
(enter)  
`(gdb) info sources -dirname qt_ws` to filter and to find sources in the program  
`(gdb) b .../qt_ws/src/main.cpp:10` to set a breakpoint  
`(gdb) r` to run the program  
`(gdb) n or s` to continue to the next line  

### GDB tips
`qt_ws/build$ gdb -tui ./qt` or pressing `Ctrl+X A` in `(gdb)` shows code  
`Ctrl+X A` in `(gdb)` changes the active window and it's possible to scroll up down with arrow keys  
`Ctrl+X O` in `(gdb)` focuses on the next window  
`Ctrl+X N` in `(gdb)` switches to the next source file  
`Ctrl+X S` in `(gdb)` Opens a new source file  
`(gdb) print variable_name` shows the value of the 'variable_name' during running the app  
`(gdb) info b` to see breakpoints or `(gdb) i b`  
`(gdb) del <num>` to delete breakpoint(s) or `(gdb) del 1-4`  
`(gdb) directory ../src` to set a search point of directory  
`(gdb) list Home (tap)(tap)` to see a code snippet after above directory setting  


## Format
[clang-format](.clang-format). After coding, press `Ctrl + Shift + I` for auto formatting.  
## Patterns
With the UI implementations, MVC would be [good](https://stackoverflow.com/questions/9419147/which-software-design-patterns-do-common-gui-frameworks-exhibit). Frontend-Backend.  
So, combination of below.  
### Creational Design Pattern
- Abstract Factory
### Structural Design Pattern
- **Bridge**
### Behavioral Design Pattern
- Observer
## Diagrams
### Class Diagram
```mermaid
---
title: UI class diagram example
---
classDiagram
    note "Abstact Factory, Observer, Bridge"
    MenuBarFactorySubscriber <--o MenuBarPublisher
    MenuBarFactorySubscriber <|.. MenuBarBase
    MenuBarBase <|-- Home
    MenuBarBase <|-- ProgressBar
    MenuBarBase <|-- Layout
    EventBridge <|-- Home
    EventBridge <|-- ProgressBar
    EventBridge <|-- Layout
    EventBridge o--> OSBridge
    OSBridge <|.. Windows
    OSBridge <|.. Linux
    OSBridge <|.. Laptop

    class MenuBarPublisher{
        -subscribers: Subscriber[]
        -mainState
        +subscribe()
        +unsubscribe()
        +notify()
    }
    class MenuBarFactorySubscriber{
        <<interface>>
        +signal()
        +slot()
        +menuBarUpdate()
        +createMenuBar()
        +createMenu()
        +createAction()
    }
    class MenuBarBase{
        +createMenuBar()
        +createMenu()
        +createAction()
    }
    class Home{
        +Home()
        +signal()
        +slot()
        +menuBarUpdate()
    }
    class ProgressBar{
        +ProgressBar()
        +signal()
        +slot()
        +menuBarUpdate()
    }
    class Layout{
        +Layout()
        +signal()
        +slot()
        +menuBarUpdate()
    }
    class EventBridge{
        +event1()
        +event2()
        +event3()
    }
    class OSBridge{
        <<interface>>
        -Windows
        -Linux
        -Laptop?
        +setVolume()
        +setScreenBrightness()
        +drawLayout()
    }
    class Windows{

    }
    class Linux{

    }
    class Laptop{

    }
```
### State Diagram
```mermaid
---
title: UI State diagram example
---
stateDiagram-v2
    [*] --> Home
    Home --> MenuBar
    Home --> ProgressBar
    Home --> Layout
    ProgressBar --> MenuBar
    Layout --> MenuBar
    MenuBar --> Home: goHome()
    MenuBar --> [*]: exitApp()
```
## Development notes
- An email can be sent through ubuntu terminal.
  - [https://stackoverflow.com/questions/70730838/how-to-send-email-with-gmail-using-curl-in-c](https://stackoverflow.com/questions/70730838/how-to-send-email-with-gmail-using-curl-in-c)
- An email will be sent via the google SMTP server. A google account with app password are needed. [You need to set](https://support.google.com/mail/answer/185833?hl=en)
  1. 2-Step Verification 
  2. App password
   
  The App password will be used for the curl command.

## References
- [Relationship between Qwidget and Qlayout](https://stackoverflow.com/questions/24262564/convert-between-qlayout-and-qwidget)