# Notes from lecture 2: make and makefiles

First note that cmake and any other generator ultimately produce a makefile. For small projects, it may be worth writing the makefile directly.

- `Make` automates the building process by defining **prerequisites-to-target** rules.
  - Note that make can work with any file type, not just C/C++. Essentially, anywhere there is a specified set of rules (e.g., building automatic documentation).

## Makefile syntax

- Commands are prepended by a **tab** character (not **spaces**!). Every line starting with **tag** IS a command.
- **Targets** are specificed as in cmake, but manually. A **prerequisite** is a target or an action that needs to be done before another. More prerequisites are separated by a space. For example, writing down all steps:

    ```makefile
    main: main.o <other_prerequisite_targets>
     g++ -o main main.o <other_prerequisite_targets>
    main.o: <other_prerequisite_targets>
     g++ -c -I<include_dir> -O2 <source_file>
    ```

- Makefiles provide tools to avoid verbose writing. Special compiler options are for instance:

    1. `-MMD`: generate dependency files for each source file.
    2. `-MP`: generate phony targets for each dependency (i.e. an action to be performed).
    3. `CPPFLAGS` and `CXXFLAGS`: flags for the C preprocessor and C++ compiler, respectively. For example, `-I<include_dir>` to add an include directory is in `CPPFLAGS`.

- Make works recursively. A single line can work on multiple entries of a **variable** directly. `$()` gets the value of a variable.
- Values of variables can be changed "on the fly" by specifying them in the command line. For example, `make CXXFLAGS=-O3` will override the default value of `CXXFLAGS` in the makefile.
  - Clearly, when using "set" or "option" in cmake, this is what is using under-the-hood.
- Variables can be exported to the environment using `export` command, just like in bash. Recall that only environment variables are available to subprocesses started in that environment. Use `env` to see the environment variables.

#### Stopped at timestamp -56 minutes