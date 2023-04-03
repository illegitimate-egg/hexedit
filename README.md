<div align="center">
<img src=".github/assets/logo.png" width="50%" />

### Hex editor written by [illegitimate-egg](https://github.com/illegitimate-egg)

<br>
</div>

[//]: # (<img src="logo.png" width="50%" align="right" />)

# Description
I was tired of there being no good terminal hex editors. So I took matters into my own hands. It's written entirely using `c` and `ncurses` with no extras.

It comes with multiple ways to install, from a cURL-to-Bash approach to a simple nix run command.

> **Note** this software is currently in very early development and only the nix install method has been verified.

# Installation
Using `cURL`:
```bash
curl -sSL raw.githubusercontent.com/illegitimate-egg/hexedit/main/install.sh | sh
```
Using `wget`:
```bash
wget -qO- raw.githubusercontent.com/illegitimate-egg/hexedit/main/install.sh | sh
```
Using `Nix`:
```bash
nix run github:illegitimate-egg/hexedit
```

# Compilation
Compiling is easy, only dependencies are `gcc` and `ncurses`.
```bash
git clone https://github.com/illegitimate-egg/hexedit.git
cd hexedit/
make
sudo make install
```
With `Nix`, it's even easier. You can just `nix shell github:illegitimate-egg/hexedit` or `nix develop github:illegitimate-egg/hexedit` to have all the dependencies ready for you. To build directly you can just:
```bash
nix build github:illegitimate-egg/hexedit
```
<div align="center">
<hr>

### Made with `c` and `ncurses`

</div>
