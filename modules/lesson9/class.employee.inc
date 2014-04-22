<?php

/**
 * This lesson introduces many-to-many relations.
 *
 * The basis of implementing a many-to-many relation is 'normalization'.
 * This means that, like in the database, the relation is represented
 * by an intermediary node. This intermediary node has 2 manytoone
 * relations with the nodes on both sides of the manytomany relation.
 * 
 * See the file class.employeeproject.inc for the node that links 
 * many projects to many employees.
 * 
 * For simplicity, we're using the employee class from lesson 1 as 
 * the basis.
 */
class employee extends atkMetaNode
{
    protected $table      = "lesson9_employee";   
    protected $index      = "name";
    protected $order      = "name";
    protected $flags      = array(NF_ADD_LINK);
    protected $descriptor = "[name]";
    
    public static function meta($policy)
    {
        $policy->get("name")->addFlag(AF_UNIQUE|AF_SEARCHABLE);
        $policy->get("salary")->addFlag(AF_TOTAL); 
        
        /**
         * The following code is where we add the manytomany relation.
         * The 'through' parameter tells ATK what intermediary node
         * to use (normalization). 
         * In this case, we use a shuttle relationship. In the project
         * node we'll demonstrate a different type of relationship.
         * Available types are: shuttle, eshuttle, select, bool, list
         * If you don't specify a type, you'd get a shuttle by default
         * but we're specifying it anyway for the sake of example.
         */
        $policy->hasMany("projects", array("type"=>"shuttle",
                                           "through"=>"employeeproject" ));
    }

    public function adminFooter()
    {
      return nodeSourceUrl("lesson9.employee");
    }
}


