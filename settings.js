    Ext.define("OMV.module.admin.service.shoutcast.Settings", { // Define a new class
    extend: "OMV.workspace.form.Panel", // What is the base type of this class

    rpcService: "shoutcast", // Remote Procedure Call
    rpcGetMethod: "getSettings", // Remote Procedure Call
    rpcSetMethod: "setSettings", // Remote Procedure Call

    getFormItems: function() { // Generic function for this class that initializes the GUI
       return [{
          xtype: "fieldset", // Type of the item
          title: _("General settings"), // Text that is shown on the top edge of the fieldset
          fieldDefaults: {
             labelSeparator: ""
          },
          items: [{ // These items are inside the fieldset item defined above
             xtype: "checkbox", // Type of the item
             name: "enable", // Individual name of the item
             fieldLabel: _("Enable"), // Text that is shown next to the checkbox. Keep this under 15 characters
             checked: false // Default value if no settings have been applied yet, Try to change this to true
             },
             {
             xtype: "numberfield", // Type of the item
             name: "maxuser", // Individual name of the item
             fieldLabel: "Max User", // Text that is shown next to the number field. Keep this under 15 characters
             minValue: 1, // Self explanatory
             allowDecimals: false, // Self explanatory
             allowBlank: false // Self explanatory
             },
             {
             xtype: "textfield",
             name: "password",
             fieldLabel: "Connection Password",
             allowBlank: false,
             },
             {
             xtype: "numberfield",
             name: "portbase",
             fieldLabel: "Listen To Port",
             minValue: 1,
             maxValue: 65535,
             allowDecimals: false,
             allowBlank: false,
             },
             {
             xtype: "numberfield",
             name: "namelookup",
             fieldLabel: "Name Lookups",
             allowBlank: false,
             minValue: 0,
             maxValue: 1,
             },
             {
             xtype: "textfield",
             name: "adminpassword",
             fieldLabel: "Admin Password",
             allowBlank: false,
             },
             {
             xtype: "numberfield",
             name: "showlastsong",
             fieldLabel: "Last Song Count",
             allowDecimals: false,
             }]
          }];
    }
    });

    // Register the class that is defined above
    OMV.WorkspaceManager.registerPanel({
    id: "Settings", //Individual id
    path: "/service/shoutcast", // Parent folder in the navigation view
    text: _("ShoutCast"), // Text to show on the tab , Shown only if multiple form panels
    position: 10, // Horizontal position of this tab. Use when you have multiple tabs
    className: "OMV.module.admin.service.shoutcast.Settings" // Same class name as defined above
    });
