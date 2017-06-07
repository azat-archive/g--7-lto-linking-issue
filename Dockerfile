FROM base/archlinux

RUN pacman -Sy --noconfirm
RUN pacman -S gcc boost cmake ninja --noconfirm --force
