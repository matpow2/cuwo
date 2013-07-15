![cuwo](http://mp2.dk/cuwo/logo.png)
====

cuwo is an open server implementation for Cube World, and includes various
utilities to manipulate its data.

Running
=======

See the [quick-start guide](https://github.com/matpow2/cuwo/wiki) for a 
quick way to get started.

Status
======

Right now, cuwo has a server that can serve clients. Players can see each other
in the game, but a lot still needs to be done. There is a basic scripting
system in place, which allows for chat commands, etc.

There is also a working MITM server that can inject packets. It's useful for
reverse-engineering the protocol and can be used as an alternative to a
standalone server.

There is also a working Cube World/Qubicle model converter. Find it in the 
'tools' folder.

Special thanks
==============

Sarcen - help with some protocol variables

Perl - protocol RE

DRayX - encrypt.py and protocol RE

MAT4DOR - cub model details

Xaymar - RE and character details

FAQ
===

Q. How do I pronounce 'cuwo'?

A. It's pronounced the same way you would pronounce cu(be)wo(rld)! :-)

Q. What is the MITM server?

A. The MITM server sits between your client and server, and can manipulate
   and inject packets. It's not really useful for the average user, so use the
   normal server instead.

