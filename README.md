![cuwo](http://mp2.dk/cuwo/logo.png)
====

cuwo is an open server implementation for Cube World, written in Python.
It currently has the best protocol coverage among all the server projects out
there, and has features like

* Cross-platform (Windows, Mac OS X, Linux, FreeBSD, etc.)
* Scripting (see the minimal scripts/welcome.py example)
* Advanced configuration
* Commands (/kick, /say, /whereis, /etc.)
* Rights management
* IRC bot

Running
=======

On Windows, see the [quick-start guide](Quickstart) for a quick way to get
started.

On Linux/Mac OS X/FreeBSD/etc., make sure you have Python 2.7 and Twisted
installed on your machine, then run run_server.sh. 

Status
======

Right now, cuwo has a server that can serve clients. Players can join/leave 
and see each other in the game, but a lot still needs to be done. There is a
scripting interface in place which allows for chat commands and administration

There is also a working MITM server that can inject packets. It's useful for
reverse-engineering the protocol and can be used as an alternative to a
standalone server.

There is also a working Cube World/Qubicle model converter. Find it in the 
'tools' folder.

FAQ
===

Q. How do I pronounce 'cuwo'?

A. It's pronounced the same way you would pronounce cu(be)wo(rld) :-)

Q. What is the MITM server?

A. The MITM server sits between your client and server, and can manipulate
   and inject packets. It's not really useful for the average user, so use the
   normal server instead.

Special thanks
==============

Sarcen - help with some protocol variables

Somer - help with some protocol variables

Perl - protocol RE

DRayX - encrypt.py and protocol RE

MAT4DOR - cub model details

Xaymar - RE and character details