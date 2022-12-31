# TuringAltair

A personal computer built with Arduino that allows one to document their experiences, notes, etc as documents like a normal personal computer. 

TuringAltair serves as a simple quick documenting tool that allows one to note-take events that occur quickly. Lectures, Speeches, Events, etc, are all places where TuringAltair can serve as a tool to save information without having to worry about unlocking your computer or phone and launching your desired Note App.

## TuringAltairPassword

TuringAltair can also act as a password manager. Users are prompted with a password to unlock their altair to access their documents. Although it slows down the process, it ensures security within the Arduino local data storage. 

# 📸 TuringAltair Screenshots

![IMG_0956.jpg](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/62773a12-972e-4a02-9848-596e46b490a5/IMG_0956.jpg)

![IMG_0957.jpg](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/7592480e-194f-4f48-b2de-e54b66cdbb9c/IMG_0957.jpg)

![IMG_0958.jpg](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/bbf60acf-ac89-460a-9288-14bf565765c2/IMG_0958.jpg)

![IMG_0955.jpg](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/d71344e7-e534-4521-b640-0263fc465a96/IMG_0955.jpg)

# 🔧 Setup Instructions

Connect the Arduino system to 9V battery supply. This is to ensure that both the DC Motor and LCD gain enough power to run. 

************Note:************ 6V or 5V is not enough for this system. If the DC motor starts to run, the LCD brightness will decrease due to lack of electricity. However, it should be recognized that this problem is still being worked on.

### Creating a Document

To create a document, press:

```swift
A
```

The LCD will prompt a message: “Document Launched”. After the message disappears, you are now able to write on the document. 

**********************User Note:********************** You can at most only print 16 characters as there are only 16 characters that an LCD can display. An hardware upgrade of the LCD is possible and can expand the total number of characters that can be displayed.

### Deleting a Character

A user can delete a character simply by typing on the keypad:

```swift
*
```

### Formatting a Document

A user can also format their unsaved document or command by typing on the keypad:

```swift
#
```

## Saving Documents

After successfully writing the document desired, you can save it by typing on the keypad:

```swift
C
```

This will display on the LCD 4 indices or in other words, 4 directories where your document can be saved. If there is no document saved on the directory, the LCD outputs `_`. 

After the iteration of each index is saved, the LCD will prompt the user an index with the message:

```swift
"Index: "
```

The user has the option to type the any number from 0 to 3:

- First Directory: Keypad Number → `0`
- Second Directory: Keypad Number → `1`
- Third Directory: Keypad Number → `2`
- Fourth Directory: Keypad Number → `3`

**********User Note:********** It should be acknowledged that with only four directories, TuringAltair can only hold 4 documents at a time. 

With the above note, if you save a document  in a directory where another document is already present, the new document will override the old one at that very directory. 

## Displaying Documents

You can display all your directories with the keypad:

```swift
B
```

The LCD will display iteratively the current state of the 4 directories. If there is no document saved, the LCD will ouput `_`.

## Checking System Temperature

TuringAltair also believes in user safety. Therefore, the system allows the user to view its temperature for regulation. 

A user can check the temperature on the keypad with:

```swift
D
```

Automatically, if the surrounding temperature of the environment is greater than 30 degrees celsius, the DC motor fan will turn on. This is to ensure that the Arduino nor the motor gets warm, ruining the performance of the system.

# Problems & Reflection

There were many problems during development. Most of them are documented under “Development Stages” found below.

<aside>
🚶 [Development Stages](https://www.notion.so/8e92dc542dd348019b07a13cf44e01db)

</aside>

One of the major ones was hardware issues. TuringAltair before using local storage was supposed to be connected to Firebase. However, although having the ESP8226 Module, the mohterboard did not support wifi connections, which were causing library issues during programming. This is a hardware issue and can be solved in the future with hardware upgrades, such as investing in an Arduino Wifi Uno. 

Another major issue was with the keypad. The keypad has limited characters, which limited the number of commands and versatility of what can be typed. Once again, this is a hardware issue, and we believe this can be solved with a bigger matrix. 

One of the major issues in terms of software was the data structure development. Arduino’s interface for c++ does not support vectors and vanilla c++ libraries, which limited to the backend structure being a simple 2D dynamic array. An upgrade to a rasberry pi is required in order to integrate faster and larger data structures.

# Updates and Future Plans

TuringAltair is still in its first beta version, and is continously being worked on. Found below are some of the future updates we plan on integration. It should be noted that the dates are not set yet.

### Investing in Larger Hardware

TuringAltair needs a hardware investment ranging from a larger breadboard, bigger matrix input module, larger LCD, and a motherboard that supports wifi (i.e, Arudino Wifi Uno). 

This is needed to allow cloud storage integration (Firebase) along with a more organized simple hardware design with larger versatility with the commands and characters it can input and display.

### Cloud Integration

In the near future, we aim to integrated Firebase to allow larger number of documents to be saved. We have made progress with investing in the Esp2866 module, but we as stated above, we lack the hardware for the motherboard. Nevertheless, Firebase connections will allow users to write more as well as saving documents without having to worry about overriding their files.

# Developer Contact

Any questions or concerns? Feel free to contact me!

My socials are listed on my [README.md](http://README.md)!
