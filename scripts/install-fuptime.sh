!#/bin/bash
if [ "$EUID" -ne 0 ]
  then echo -e "\e[31mPlease run as root\e[0m"
  exit
fi
if [ -f fuptime ]; then
    echo -e "\e[32mFuptime binary exists in the current directory\e[0m"
else
    echo -e "\e[31mFuptime binary does not exist in the current directory\e[0m"
    exit 1
fi

if [ -f /usr/bin/fuptime ]; then
    echo -e "\e[31mFuptime is already installed in /usr/bin\e[0m"
    echo -e "\e[33mDo you want to reinstall fuptime? (y/n)\e[0m"
    read -r reinstall
    if [ "$reinstall" = "y" ]; then
        rm /usr/bin/fuptime
        cp fuptime /usr/bin/fuptime
        echo -e "\e[32mFuptime has been reinstalled\e[0m"
        exit 0
    else
        echo -e "\e[32mFuptime has not been reinstalled\e[0m"
        exit 1
    fi
else
    echo -e "\e[32mFuptime will be installed in /usr/bin\e[0m"
    echo -e "\e[33mDo you want to install fuptime? (y/n)\e[0m"
    read -r install
    if [ "$install" = "y" ]; then
        cp fuptime /usr/bin/fuptime
        echo -e "\e[32mFuptime has been installed\e[0m"
        exit 0
    else
        echo -e "\e[32mFuptime has not been installed\e[0m"
        exit 1
    fi
fi