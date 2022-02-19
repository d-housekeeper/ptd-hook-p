# ptd-hook
Read original [README](README_ORIG.md).

## Build memo
Ubuntu 20.04.1

### Nix
nix-* not in PATH after install https://github.com/NixOS/nix/issues/3317

#### Update ptd-tool
Edit [ptd-tool/default.nix](ptd-tool/default.nix)
* version
* sha256

`nix-prefetch-url URL` gets fetchurl sha256.
