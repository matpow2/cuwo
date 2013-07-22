![cuwo](http://mp2.dk/cuwo/logo.png)
====

cuwo is an open server implementation for Cube World, written in Python.
It currently has the best protocol coverage among all the server projects out
there, and has features like

* Cross-platform support (Windows, Mac OS X, Linux, FreeBSD, what have you)
* Registration and Login system
* Console logging
* MOTD message
* Scripting (see scripts in ./scripts directory)
* Advanced configuration
* Ban system
* Commands
    ... for players:
        * /register <password>
        * /login <ID> <password>
        * /list (also is showing classes and levels)
        * /tell <player> <message>
        * /whois [player] (shows class and level of you or another player)
    ... for admins:
        * /kick <player>
        * /say <message>
        * /setclock <time>
        * /kill [player]
* SQLite database for storing permanent data
    * For faster access it is kept in memory
    * Asynchronous database queries
    * R*-Tree regions, region groups and triggers possible in near future
    * Saves player data like ID, password hash (SHA224 with salt), (last) online time, last IP connected with
    * Bans for both player IDs and IPs
    ... and more in future
* Lower CPU requirements than normal server
* ... and much more!

Running
=======

On Windows, see the
[quick-start guide](https://github.com/matpow2/cuwo/wiki/Quickstart) for a
quick way to get started.

On Linux/Mac OS X/FreeBSD/etc., make sure you have Python 2.7 and Twisted
installed on your machine, then run run_server.sh.

Status
======

In terms of gameplay, the following has been implemented:
* Player join/leave
* Player movement and animations
* Teleportation
* Magic/arrows/etc. relay
* Player hits on entities/other players
* Item pickup/drop
* Time management

A lot is still to be implemented gameplay-wise. Most importantly, NPCs and mobs
have not been implemented yet. We still need to rip out the terrain generator,
and once that's done, NPCs and mobs should be completely doable.

There is also a working MITM server that can inject packets. It's useful for
reverse-engineering the protocol and can be used as an alternative to a
standalone server.

There is also a working Cube World/Qubicle model converter. Find it in the
'tools' folder.

FAQ
===

* **Q.** How do I pronounce 'cuwo'?

* **A.** 'coo-woo' (no, not 'kew-woh')

* **Q.** I am not a programmer, and I can't reverse-engineer anything. How do
         I help?

* **A.** We need people who can create end-user documentation as well! Have a
         look around, and see if anything is missing in the wiki.

* **Q.** What is a MITM server?

* **A.** A MITM server sits between your client and server, and can manipulate
         and inject packets. It's not really useful for the normal user, so
         use the regular cuwo server instead.

Special thanks
==============

Sarcen - help with some protocol variables, scripting

Perl - protocol RE

Somer - help with some protocol variables

Favorlock - scripting and commands

Jakky89 - SQLite database integration, scripting, commands

Kainzo - Testing

DRayX - encrypt.py and protocol RE

MAT4DOR - cub model details

Xaymar - RE and character details