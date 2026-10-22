# Mirarium

[![GitHub](https://img.shields.io/badge/GitHub-mksushka%2FMirorium-181717?logo=github)](https://github.com/mksushka/Mirorium)

Mirarium is a fork of Git, built for experimentation, education, and source-control tooling development while staying close to the Git command-line ecosystem.

This repository contains a Git-compatible codebase with the usual Git plumbing, porcelain commands, documentation, and supporting utilities. It is intended for developers who want to inspect, modify, build, and extend Git-style workflows in a single project tree.

## Why Mirarium?

- Git-compatible behavior and data model
- Direct access to upstream-style internals and command suite
- Good base for experimentation with repository tooling and workflows
- Fast way to learn how Git is implemented under the hood

## Features

- Core Git functionality and command set
- Repository plumbing and object database support
- Built-in scripts and command wrappers
- GUI and web-related tooling (`git-gui`, `gitk-git`, `gitweb`)
- Documentation, tests, and compatibility infrastructure

## Quick start

Clone the project and build it:

```bash
git clone https://github.com/mksushka/Mirorium.git
cd Mirorium
make configure
./configure --prefix=/usr/local
make
make install
```

If you only want to test locally without a global install, you can also build and run directly from the tree:

```bash
make
./bin-wrappers/git --version
```

## Build and test

Typical development workflow:

```bash
make
make test
```

For documentation or packaging-related builds, the repository also supports standard Git-style install targets described in `INSTALL`.

## Repository layout

- `Documentation/` — project and Git documentation resources
- `builtin/` — built-in Git commands
- `contrib/` — community and auxiliary tools
- `git-gui/` — graphical Git interface
- `gitk-git/` — gitk browser sources
- `gitweb/` — Git web interface
- `t/` — test suite
- `src/` — project source tree
- `po/` — translations
- `templates/` — templates and generated content

## Development notes

This project follows the Git development model closely, including:

- standard `make`-based builds
- test-driven validation via the `t/` suite
- source patches reviewed in the same spirit as upstream Git contributions
- compatibility with Git workflows and conventions

## Contributing

Contributions are welcome. For changes, prefer a clean, focused patch and keep behavior aligned with the Git model used by the project.

Before submitting work:

```bash
make test
```

Then share the patch in the usual Git/patch workflow used by the project.

## License

Mirarium is distributed under the same broad licensing model used by Git. See `COPYING` for the full license text.

## Related files

- `INSTALL` — build and installation instructions
- `Documentation/` — docs and references
- `COPYING` — license information
- `RelNotes` — release notes

---

Mirarium is a learning-oriented Git fork: a practical place to inspect, build, and experiment with Git internals and command behavior.
