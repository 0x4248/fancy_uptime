!#/bin/bash

if [ "$EUID" -ne 0 ]
  then echo -e "\e[31mPlease run as root\e[0m"
  exit
fi
if [ -f /usr/bin/fuptime ]; then
    echo -e "\e[32mFuptime is installed in /usr/bin\e[0m"
    echo -e "\e[33mDo you want to uninstall fuptime? (y/n)\e[0m"
    read -r uninstall
    if [ "$uninstall" = "y" ]; then
        rm /usr/bin/fuptime
        echo -e "\e[32mFuptime has been uninstalled\e[0m"
        exit 0
    else
        echo -e "\e[32mFuptime has not been uninstalled\e[0m"
        exit 1
    fi
else
    echo -e "\e[31mFuptime is not installed in /usr/bin\e[0m"
    exit 1
fi