# andon

**A Google Paper Signals-inspired notification system written in Python and Arduino C.**

According to **Wikipedia**:

> **Andon (Japanese: アンドン or あんどん or 行灯)** is a manufacturing term referring to a system to notify management, maintenance, and other workers of a quality or process problem. The centerpiece is a device incorporating signal lights to indicate which workstation has the problem.

``andon`` is a combination of two projects:

    1. ``nodemcu_client``: This is the client-side, to be installed on a NodeMCU Chip. 
    2. ``andon_webserver``: The server side is to be installed on a Linux machine of your choice, preferably a Raspberry Pi (any flavour should do).

``andon`` hopes to be similar, in spirit, to the ``Google Paper Signals`` project, but a little more powerful in what it can do.

## Features List

### Server Side

    * Voice integration, using ``voicehat`` and ``google_speech``.
    * Chat integration, similar to ``google assistant``, but over a rest api, 
    to be accessed via a browser. I'm going to use ``Flask``, ``Bulma.io`` and ``ES6`` for this.

### Client side

    * Rest API, coded in ``arduino c``.
    
