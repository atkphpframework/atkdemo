<?php

  /**
   * This node is similar to the employee 1 node that you saw before.
   *
   * The addition in this lesson is we are again going to customize
   * it like in employee 3, but now like the 'old' fashion way.
   */
  atkimport("atk.atkmetanode");
  userelation("atkManyToOneRelation");

  class lesson6_employee2 extends atkMetaNode
  {
    // Instead of creating a meta function, we now add
    // a normal constructor.
    function Lesson6_Employee2()
    {
      // In the constructor we call the atkMetaNode which will
      // generate the complete node.
      $this->atkMetaNode();

      // To override a field, it's now a matter of adding
      // an attribute to the node, like in lesson 1.
      $this->add(new atkAttribute("notes", AF_BLANK_LABEL));

      $this->add(new atkManyToOneRelation("lesson6_department_id","lesson6.lesson6_department", AF_SEARCHABLE));
    }

    function adminFooter()
    {
      return nodeSourceUrl("lesson6.lesson6_employee2");
    }
  }

?>