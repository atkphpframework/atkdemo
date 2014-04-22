<?php

  /**
   * This node is similar to the department node of lesson 4.
   * The addition is an implementation of 'recordActions'.
   * In this lesson, a department can only be edited by it's
   * members. If a user is logged in, he can only edit his
   * own department.
   */

  userelation("atkonetomanyrelation");
  useattrib("atkboolattribute");

  class department extends atkNode
  {
    function department()
    {
      $this->atkNode("department", NF_ADD_LINK);

      $this->add(new atkAttribute("id", AF_AUTOKEY));
      $this->add(new atkAttribute("name", AF_OBLIGATORY|AF_UNIQUE|AF_SEARCHABLE));

      $this->add(new atkOneToManyRelation("employees","lesson5.employee","department_id", AF_HIDE_LIST), "employees");

      $this->add(new atkBoolAttribute("is_hiring"));

      $this->setOrder("name");
      $this->setTable("lesson5_department");
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

    /**
     * The recordActions method can be implemented to add or remove actions
     * for a record.
     */
    function recordActions($record,&$actions)
    {
      /**
       * First we determine the currently logged in user.
       */
      $user = atkGetUser();

      /**
       * Then we compare the department_id of the employee, with the record
       * we are currently editing. A user may only edit his own department and
       * the administrator can edit all records
       */
      if ('administrator'!=$user['name'] && $record["id"]!=$user["department_id"])
      {
        /**
         * If they do not match, the edit and delete actions are removed from
         * this records' action list.
         */
        unset($actions["edit"]);
        unset($actions["delete"]);
      }
    }

    function adminFooter()
    {
      return nodeSourceUrl("lesson5.department");
    }
  }
?>
