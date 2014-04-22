<?php

  atkimport("atk.atkmetanode");
  useattrib("atkboolattribute");
  userelation("atkonetomanyrelation");

  class lesson6_department extends atkMetaNode
  {
    function lesson6_department()
    {
      $this->atkMetaNode();
      $this->add(new atkBoolAttribute("is_hiring"));
    }

    function name_display($record)
    {
      $nameattr = &$this->getAttribute("name");
      $org = $nameattr->display($record);

      if ($record["is_hiring"])
      {
        $org = '<b>'.$org.'</b>';
      }

      return $org;
    }

    function employees_edit($record, $mode)
    {

      $employees = &$this->getAttribute("employees");

      if (!$record["is_hiring"])
      {
        $node = &$employees->getDestination();
        {
          $node->addFlag(NF_NO_ADD);
        }
      }

      return $employees->edit($record, $mode);
    }

    function descriptor_def()
    {
      return "[name]";
    }

    function adminFooter()
    {
      return nodeSourceUrl("lesson6.lesson6_department");
    }
  }
?>