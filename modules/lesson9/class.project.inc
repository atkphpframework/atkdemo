<?php

/**
 */

class project extends atkMetaNode
{
    protected $table = "lesson9_project";
    protected $flags = array(NF_ADD_LINK);
    protected $index = "name";
    protected $order = "name";
    protected $descriptor = "[name]";
    
    public static function meta($policy)
    {
        $policy->get("name")->addFlag(AF_SEARCHABLE|AF_UNIQUE);
        
        /**
         * The select relation is a manytomany type relation represented
         * by a set of selected records and a selection field. Like in 
         * the class.employee.inc example in this module, the parameters 
         * represent the intermediary node and the relationship type.
         */
        $policy->hasMany("employees", array("through"=>"employeeproject",
                                            "type"=>"select"));
    }

    function adminFooter()
    {
      return nodeSourceUrl("lesson9.project");
    }
  }
