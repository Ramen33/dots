#!/bin/sh
picom --no-fading-openclose &
#picom &
#lxqt-policykit-agent
#slstatus &
xset r rate 200 50 &
sudo xinput set-prop 10 311 0 &
nitrogen --restore &
~/bar &
dbus-update-activation-environment --all &
xrdb -merge ~/.Xresources
dunst &
unclutter --timeout 5 &
#xautolock -time 10 -locker "slock" &
#exec i3
#polybar -r &
exec dwm
#exec 2bwm
