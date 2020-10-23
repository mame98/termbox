# Termbox

> This project is a fork of [nsf/termbox](https://github.com/nsf/termbox)
> which is not maintained for quite some time.

Termbox is a library that provides minimalistic API which allows the
programmer to write text-based user interfaces.

It is based on a very simple abstraction. The main idea is viewing terminals as
a table of fixed-size cells and input being a stream of structured
messages. Would be fair to say that the model is inspired by windows console
API. The abstraction itself is not perfect and it may create problems in certain
areas. The most sensitive ones are copy & pasting and wide characters (mostly
Chinese, Japanese, Korean (CJK) characters). When it comes to copy & pasting,
the notion of cells is not really compatible with the idea of text. And CJK
runes often require more than one cell to display them nicely. Despite the
mentioned flaws, using such a simple model brings benefits in a form of
simplicity. And KISS principle is important.

At this point one should realize, that CLI (command-line interfaces) aren't
really a thing `termbox` is aimed at. But rather pseudo-graphical user interfaces.

### Installation

In order to build `termbox` you need to use *CMake*

```shell script
mkdir build && cd build                 (create build directory)
cmake .. [options]                      (configure build system)
make                                    (build library)
make install                            (install library)
```

##### Python

>
> The Python module will probably not work right now. First the
> C library needs to be maintained
>

### Getting started

Termbox's interface only consists of 12 functions::

```
tb_init() // initialization
tb_shutdown() // shutdown

tb_width() // width of the terminal screen
tb_height() // height of the terminal screen

tb_clear() // clear buffer
tb_present() // sync internal buffer with terminal

tb_put_cell()
tb_change_cell()
tb_blit() // drawing functions

tb_select_input_mode() // change input mode
tb_peek_event() // peek a keyboard event
tb_poll_event() // wait for a keyboard event
```

See [`src/termbox/termbox.h`](src/termbox/termbox.h) header file for full detail.

### Links

##### Other implementations

- https://github.com/nsf/termbox - The original termbox project
- https://github.com/nsf/termbox-go - Go pure Termbox implementation

### Bugs & questions

Report bugs to the https://github.com/mame98/termbox issue tracker.