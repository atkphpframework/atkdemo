<?php

  useattrib("atktextattribute");
  useattrib("atkdateattribute");
  useattrib("atknumberattribute");
  userelation("atkmanytoonerelation");

  class employee extends atkNode
  {
    function employee()
    {
      $this->atkNode("employee", NF_ADD_LINK);

      $this->add(new atkAttribute("id", AF_AUTOKEY));
      $this->add(new atkAttribute("name", AF_OBLIGATORY|AF_UNIQUE|AF_SEARCHABLE));

      $dpt = &$this->add(new atkManyToOneRelation("department_id","lesson10.department", AF_SEARCHABLE));

      $mgr = &$this->add(new atkManyToOneRelation("manager_id","lesson10.employee", AF_SEARCHABLE));
      $mgr->addDestinationFilter("department_id = '[department_id.id]' AND id<>'[id]'");
     
      $dpt->addDependee("manager_id");


      $this->add(new atkDateAttribute("hiredate"));
      $this->add(new atkNumberAttribute("salary", AF_TOTAL));
      $this->add(new atkTextAttribute("notes", 0, AF_HIDE_LIST));

      $this->setOrder("name");
      $this->setIndex("name");
      $this->setTable("lesson3_employee"); // reuse tables from lesson3
    }

    function descriptor_def()
    {
      return "[name]";
    }

    function adminFooter()
    {
      return nodeSourceUrl("lesson10.employee");
    }

  }


?>