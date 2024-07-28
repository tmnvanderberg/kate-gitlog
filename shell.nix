{ pkgs ? import <nixpkgs> {} }:

pkgs.mkShell {
  buildInputs = [
    pkgs.extra-cmake-modules
    pkgs.libsForQt5.ktexteditor
    pkgs.qt5.qtbase
    pkgs.git
    pkgs.cmake
    pkgs.gcc
  ];
}
