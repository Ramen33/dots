#!/bin/sh
picom --no-fading-openclose &
#picom &
sudo lxqt-policykit-agent &
#slstatus &
xset r rate 200 50 &
sudo xinput set-prop 9 311 0 &
#~/fehwall &
#feh --bg-fill ~/wallpapers --randomize &
feh --bg-fill ~/Pictures/D.png &
#nitrogen --restore &
/home/pc/scripts/sbar &
#~/scripts/sbar &
dbus-update-activation-environment --all &
xrdb -merge /home/pc/.Xresources
dunst &
unclutter --timeout 5 &
#xautolock -time 10 -locker "slock" &
#exec i3
#polybar -r &
#thunderbird --headless &
mpv ~/nt4.mp3 &
/usr/bin/xset b off &
udiskie &
mpc clear &
mpc load "1" &
exec dwm
#exec 2wm
#exec 2bwm
