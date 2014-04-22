<?php

  class mod_lesson_utils extends atkModule
  {
  }

  function nodeSourceUrl($nodetype)
  {
    list($module, $node) = explode(".", $nodetype);
    return href(dispatch_url("lesson_utils.sourceviewer", "view", array("module"=>$module, "node"=>$node)), atkText("view_source", "lesson_utils"), SESSION_NESTED);
  }

  function moduleSourceUrl($module)
  {
    return dispatch_url("lesson_utils.sourceviewer", "view", array("module"=>$module));
  }

?>
