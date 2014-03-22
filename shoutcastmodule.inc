      #!/bin/sh
     
      set -e
     
      . /etc/default/openmediavault
      . /usr/share/openmediavault/scripts/helper-functions
     
      FILE="/root/testfile"
     
     
      cat <<EOF > $FILE
      enable=$(omv_config_get "//services/shoutcast/enable")
      maxuser=$(omv_config_get "//services/shoutcast/maxuser")
      password=$(omv_config_get "//services/shoutcast/password")
      portbase=$(omv_config_get "//services/shoutcast/portbase")
      namelookup=$(omv_config_get "//services/shoutcast/namelookup")
      adminpassword=$(omv_config_get "//services/shoutcast/adminpassword")
      showlastsongs=$(omv_config_get "//services/shoutcast/showlastsongs")
      EOF
