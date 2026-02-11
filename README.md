# CHIPPIE

CHIPPIE is yet another CHIP-8 emulator that I work on in my free time. It's written in C and uses Raylib for graphics. My general goal is just to end up with something that's enjoyable to use. [It's still a major work in progress.](#roadmap)

**The emulator is not currently usable.**

## Installation

~~If the automatic build script works, there should be builds in releases.~~ **There is no build script yet.**

I only have access to Windows and Linux systems, so if something somehow happens with MacOS or even the two platforms I do test, make an issue and I'll try and fix the problem.

If you're using an operating system not listed here or you want this to work with your OS's distribution package manager, you can always [build the project](#building).

## Building

You should be able to get away with cloning the project and running `cmake --build` in the project directory:

```bash
git clone https://github.com/AppleJuiceNerd/CHIPPIE.git
cd CHIPPIE
cmake -B build
cmake --build build
```

I haven't yet worked out information on dependencies.

## Usage

This isn't exactly the best CLI application yet, and it's really basic.

All one can do at the current moment is pass a rom into it through the first argument.

```bash
./main /Path/To/ROM.ch8
```

[Not everything works yet, though.](#roadmap)

## Roadmap

Currently the emulator can't run *all* ROMs yet, but once the core emulator is finished, I have some plans relating to the finished product of this application as a whole. These items are not necessarily chronologically ordered.

- [ ] Pass all [emulator tests](https://github.com/Timendus/chip8-test-suite) (Just CHIP-8)
- [ ] SUPER-CHIP Support
- [ ] XO-CHIP Support
- [ ] Debugging Features
- [ ] ROM Browser

For more info on the more specific details of planned features, check out [TODO.md](/TODO.md)

## Contributing

This... is a personal project right now.

## Credits

- CHIP-8 Resources
  - [chip-8-test-suite](https://github.com/Timendus/chip8-test-suite) by [Timendus](https://github.com/Timendus)
    - This is what I've used to test how the emulator functions and it seems to work great!
  - [CHIP-8 Research Facility](https://chip-8.github.io/) by [tobiasvl](https://github.com/tobiasvl)
    - This was made for the purpose of gathering useful sources information about CHIP-8 in one place. I highly recommend it if you also want to make a CHIP-8 emulator.

## License

This project is licensed under the [GNU GPLv3](https://www.gnu.org/licenses/gpl.html). See [LICENSE](/LICENSE).
