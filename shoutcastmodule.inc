      #!/bin/sh
     
      set -e
     
      . /etc/default/openmediavault
      . /usr/share/openmediavault/scripts/helper-functions
     
      FILE="/root/testfile"
     
     
      cat <<EOF > $FILE
      enable=$(omv_config_get "//services/shoutcast/enable")
      numberfield1=$(omv_config_get "//services/shoutcast/numberfield1")
      EOF
