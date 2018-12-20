# liberrors

`liberrors` is a library for debugging C programs and handling
errors in C programs smoothly.

# Requirements

To install `liberrors`, you will need:

* Access to the C standard libraries (`stdio.h`, `stdlib.h`, etc).
* Autotools
* A UNIX or UNIX-based operating system (I haven't tested it on Windows, and
I don't care about testing it on Windows).

# Installation

`liberrors` by executing the following commands:

`tar xvf liberrors-[insert version here].tar.gz`
`cd liberrors-[insert version here] && ./install_library install`

...and Vóila! Now that the library is installed, you can go on to the next
section to see some of the most useful macros and functions available.

If you decide to uninstall the library at any point, go to the directory with
the `install_library` script and run `./install_library clean`. For other
commands, just examine the information produced by running
`./install_library help`.

# Interesting Macros and Functions

`liberrors` offers a few macros for debugging and logging:

* `liberrors_log_debug(msg, ...)`
* `liberrors_log_error(msg, ...)`
* `liberrors_log_info(msg, ...)`

These macros act like `printf()` and will output an line of information with
the words, `DEBUG`, `ERROR`, or `INFO` printed as shown, respectively.

`liberrors` also offers commands for safe memory allocation such as:

* `liberrors_smalloc(int size)`
* `liberrors_scalloc(int size, int each)`
* `liberrors_srealloc(void *ptr, int size, int new_size)`

Note that `liberrors_srealloc` asks for a `new_size` and `size` integer
argument. The arguments are used by `liberrors_srealloc` to help clean up
memory and not leave any allocated pointers on the heap (this is still being
developed though).

`liberrors` also offers macros for NULL-checks and some basic exception
handling. The macros are defined as follows:

* `liberrors_assert(obj, ...)`
* `liberrors_handle_exception(ret, msg, ...)`

`liberrors_assert` checks whether `obj` is NULL and returns whatever is
provided in the `...`. Keep in mind that only **1** argument should be provided
after the `obj` argument.
`liberrors_handle_exception(ret, msg, ...)` logs an error with `msg` and its
arguments, and then proceeds to return `ret`.

Keep in mind this is a short description of macros and functions that is
not necessarily complete.
