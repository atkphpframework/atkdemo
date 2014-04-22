<?php

  /**
   * The department is a simple node with an id as primary key, and a name
   * field.
   */
  userelation("atkonetomanyrelation");

  class department extends atkNode
  {
    function department()
    {
      $this->atkNode("department", NF_ADD_LINK);

      $this->add(new atkAttribute("id", AF_AUTOKEY));
      $this->add(new atkAttribute("name", AF_OBLIGATORY|AF_UNIQUE|AF_SEARCHABLE));

      $this->add(new atkOneToManyRelation("employees","lesson10.employee","department_id", AF_HIDE_LIST));

      $this->setOrder("name");
      $this->setTable("lesson3_department"); // reuse tables from lesson 3
    }

    function descriptor_def()
    {
      return "[name]";
    }

    function adminFooter()
    {
      return nodeSourceUrl("lesson10.department");
    }
  }
?>
