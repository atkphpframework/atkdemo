<?php
  
  /**
   * The module definition class.
   *
   * This module introduces, among other things, security profiles. Employees
   * get a login name/password, and a profile.
   */
  class mod_lesson5 extends atkModule
  {           
    function getMenuItems()
    {          
      $this->menuitem("lesson5"); 
            
      $this->menuitem("departments", dispatch_url("lesson5.department", "admin"), "lesson5"); 
      $this->menuitem("employees", dispatch_url("lesson5.employee", "admin"), "lesson5"); 
      
      /** 
       * The following line adds the new profiles menuitem.
       * New here is the 4th parameter to the menuitem() call. This parameter
       * makes the menuitem disappear, if the current user does not have the 
       * 'admin' privilege on the profile node.
       * If you don't pass this parameter, the menuitem is always visible, and
       * the user will get an 'access denied' message when clicking the item
       * anyway. (you can try this by accessing the 'lesson1' menuitems when
       * logged in as one of the employees.)
       */
      $this->menuitem("profiles", dispatch_url("lesson5.profile", "admin"), "lesson5", array("lesson5.profile", "admin"));
           
      $this->menuitem("-", "", "lesson5");
      
      $this->menuitem("modulesource", moduleSourceUrl("lesson5"), "lesson5");
    }
    
    /**
     * This lesson contains security profiles. This means that no longer all
     * users may execute all actions. The administrator user still can, but
     * other users need privileges.
     * With this method, the system is instructed of the privileges that
     * exist. Usually, this corresponds to the actions that can be done
     * on a node.
     */
    function getNodes()
    {    
      /**
       * In this case, we tell the system that the employee node of the
       * lesson5 module has 'admin', 'add', 'edit' and 'delete' privileges.
       */
      registerNode("lesson5.employee", array("admin", "add", "edit", "delete"));
      
      /** 
       * If a user has the grantall privilege, he can grant other users all 
       * privileges; even privileges he does not have himself. Without this
       * privilege, users can only grant rights to other users that they have
       * themselves.
       */
      registerNode("lesson5.profile", array("admin", "add", "edit", "delete", "grantall"));
      registerNode("lesson5.department", array("admin", "add", "edit", "delete"));
    }
    
  }

?>