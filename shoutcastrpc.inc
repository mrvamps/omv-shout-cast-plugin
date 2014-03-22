      <?php
      require_once("openmediavault/module.inc");
      require_once("openmediavault/config.inc");
      require_once("openmediavault/error.inc");
      require_once("openmediavault/initscript.inc");

      class OMVModuleshoutcast extends OMVModuleServiceAbstract
          implements OMVINotifyListener, OMVIModuleServiceStatus {
     
          public function getName() { return "shoutcast";} // Module name. Same as in RPC and .js files
     
      //*****************************************************************   
      //*****************************************************************
      //*****************************************************************
     
          public function applyConfig() {
              // This function is called when the user applies the configuration changes in the web GUI
                 
              // Select the script file that is executed. (Scripts located in the mkconf folder)
              $cmd = "omv-mkconf shoutcast 2>&1";
             
              // If script fails to execute then create an error
              if(0 !== $this->exec($cmd, $output)) {
                  throw new OMVException(OMVErrorMsg::E_EXEC_FAILED, $cmd, implode("\n", $output));
              }
             
          }
     
      //*****************************************************************   
      //*****************************************************************
      //*****************************************************************
     
          public function getStatus() {

              // Reference to the global declaration of the variable $xmlConfig (Needed always)
              global $xmlConfig;
     
              // Get the configuration object.
              $xpath = "//services/shoutcast"; // Structure of the xml schema
              $object = $xmlConfig->get($xpath); // Read data from the xmlConfig file
             
              // If no data is found then create an error
              if(is_null($object)) {
                  throw new OMVException(OMVErrorMsg::E_CONFIG_GET_OBJECT_FAILED,$xpath);
              }

              // Return information to the web GUI
              // Information is shown in Diagnostics/Services
              return array(
                  "name" => $this->getName(),
                  "title" => gettext("First Plugin"),
                  "enabled" => boolval($object['enable']),
                  "running" => ("running")
              );
          }

      //*****************************************************************   
      //*****************************************************************
      //*****************************************************************
     
          function bindListeners(OMVNotifyDispatcher $dispatcher) {
          // Bind Listeners function is used to add monitoring about changes made to the configuration
          // After configuration changes It activates the message:
          // "The configuration has been changed. You must apply ... Apply button"
              $dispatcher->addListener(OMV_NOTIFY_MODIFY,
                                      "org.openmediavault.services.shoutcast",
                                      array($this, "setDirty"));
          }


      }

      // Register the Module
      $moduleMgr = &OMVModuleMgr::getInstance(); // Get the "root" instance for the Modules
      $moduleMgr->registerModule(new OMVModuleshoutcast()); // Register a new instance of the module described above
      ?>
