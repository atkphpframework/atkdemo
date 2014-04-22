<?php

/**
 * The department is a simple node with an id as primary key, and a name
 * field.
 * New is the use of the 'one to many relation'. Departments and employees
 * have a master/detail relationship, or 1:N association.
 * If you want to reflect this in an application, adding a single line is
 * enough to add master/detail functionality to the node.
 * This results in the ability to add employees directly to a department.
 */
class department extends atkMetaNode
{
    protected $table      = "lesson2_department";
    protected $order      = "name";
    protected $flags      = array(NF_ADD_LINK);
    protected $descriptor = "[name]";
    
    public static function meta($policy)
    {
        $policy->get("name")->addFlag(AF_UNIQUE|AF_SEARCHABLE);

        /**
         * The next line adds the relationship. 
         * 
         * The first parameter is the name of the entity we have a 
         * relationship with. This parameter is smart, it understands
         * words. E.g. we say 'has many employees'. The employee entity
         * is called 'employee', not 'employees', but this is OK. ATK
         * understands what you're trying to do.
         * 
         * Also, you'll note that we don't have to tell it what foreign
         * keys to use for the relationship. ATK discovers that employee 
         * has a 'department_id' field so it decides to use that as the
         * foreign key.
         */
        $policy->hasMany("employees");

    }

    public function adminFooter()
    {
      return nodeSourceUrl("lesson2.department");
    }
}
