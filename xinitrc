#!/bin/sh
picom &
sudo lxqt-policykit-agent &
xset r rate 200 50 &
sudo xinput set-prop 9 311 0 &
nitrogen --restore &
~/scripts/bar &
dbus-update-activation-environment --all &
xrdb -merge /home/pc/.Xresources
dunst &
unclutter --timeout 5 &
#xautolock -time 10 -locker "slock" &
/usr/bin/xset b off &
udiskie &
exec dwm
