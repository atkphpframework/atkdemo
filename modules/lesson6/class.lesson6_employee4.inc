<?php

  /**
   * This node is similar to the employee 2 node that you saw before.
   *
   * The addition in this lesson is we are going to customize it more
   * with new policy functions.
   */

  atkimport("atk.atkmetanode");

  class lesson6_employee4 extends atkMetaNode
  {

    function meta(&$policy)
    {
      // With the policy it's possible to get a attribute list
      // that the atkMetaNode made of your table. You can retreive
      // the list with the getAttributes() function.
      $attrs = &$policy->getAttributes();

      // Now we have the attribute list, it's possible
      // to change an attribute. For example, defeault the
      // atkMetaNode will detect an atkTextAttribute for
      // the notes field, but with the following 2 commands
      // you can change it into an atkAttribute and give
      // it the flag AF_BLANK_LABEL.
      $attrs["notes"]["type"] = "atkattribute";
      $attrs["notes"]["params"] = array(AF_BLANK_LABEL);

      // TODO: Write some docs
      $policy->hasOne("lesson6_department");

    }

    function adminFooter()
    {
      return nodeSourceUrl("lesson6.lesson6_employee4");
    }
  }

?>