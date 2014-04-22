<?php

  /**
   * This file contains the definition of an atkMetaNode. So what is an
   * atkMetanode? well it's a node that uses the meta data of the database
   * to automaticly add the attribute for the fields it find.
   *
   * First we have to import the atkMetaNode so we can extend our new class.
   */
  atkimport("atk.atkmetanode");

  /**
   * To create a module like we did in lesson 1 for the employees, we now
   * only need 1 line of code and that's the class definition. The atkMetanode
   * will look for a table called the same as the classname and then it will
   * build the node for you. In this example we have more than 1 line because
   * we also want a link to show the source of this node.
   */
  class lesson6_employee1 extends atkMetaNode
  {
    function adminFooter()
    {
      return nodeSourceUrl("lesson6.lesson6_employee1");
    }
  }

?>