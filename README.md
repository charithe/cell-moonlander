# Moonlander CEll Layout

This is a custom [Moonlander Mark 1](https://www.zsa.io/moonlander/) keyboard layout that I am currently experimenting with. The Oryx web tool is fantastic for configuring the keyboard but it lacks support for the UK keyboard layout and I couldn’t really figure out the macro UI. This layout currently does the following:

- Enable the UK keymap.
- Enable leader key
- Create a macro to drop into Vim command mode by clicking a thumb cluster button.
- Leader key combo for em-dash and Vim wq 

## Dev Setup

```
python3 -m pip install --user qmk
qmk setup -H ~/code/qmk_firmware -b firmware19 zsa/qmk_firmware
cd ~/code/qmk_firmware/keyboards/moonlander/
git submodule add git@github.com:charithe/cell-moonlander.git cell
```

## Compile

```
cd ~/code/qmk_firmware/ 
make moonlander:cell
```
