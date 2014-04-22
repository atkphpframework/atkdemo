<?php

class employeeproject extends atkMetaNode
{
    protected $table = "lesson9_employeeproject";
    
    public static function meta($policy)
    {
      $policy->hasOne("employee");
      $policy->hasOne("project");
    }
}

