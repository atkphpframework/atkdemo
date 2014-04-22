<?php

  /**
   * This node introduces the atkTreeNode. The atkTreeNode is an atkNode
   * specialisation that is created for handling data that has a hierarchical
   * structure. The adminpage is rendered as a tree instead of a recordlist,
   * to reflect the data's hierarchical structure.
   *
   * We deviate from the default employee example here because a
   * 'category' (for example product category) is more intuitive when
   * thinking of trees.
   */
  atkimport("atk.atktreenode");

  /**
   * Also, this node introduces the atkManyToOneTreeRelation. It is similar
   * to the regular atkManyToOneRelation as seen in the previous lessons,
   * but it is especially suited to create a relation to atkTreeNodes. It
   * renders the dropdown box in a tree-like fashion to reflect the data
   * structure.
   * In this example lesson, we use this relation to select a new parent
   * for a record.
   */
  userelation("atkmanytoonetreerelation");

  class category extends atkTreeNode
  {
    function category()
    {
      /**
       * The NF_TREE_* flags are specifically designed to tweak behaviour of
       * the tree. NF_TREE_NO_ROOT_COPY establishes that root items can not be
       * copied. NF_TREE_NO_ROOT_DELETE disables deletion of tree root items.
       */
      $this->atkTreeNode("category",NF_COPY|NF_TREE_NO_ROOT_COPY|NF_TREE_NO_ROOT_DELETE|NF_ADD_LINK);

      $this->add(new atkAttribute("cat_id",AF_HIDE|AF_PRIMARY|AF_AUTO_INCREMENT));
      $this->add(new atkAttribute("title",AF_SEARCHABLE|AF_OBLIGATORY));

      $this->add(new atkManyToOneTreeRelation("parent_cat_id","lesson7.category",AF_PARENT));

      $this->setTable("lesson7_category");
    }

    function descriptor_def()
    {
      return "--[title]";
    }

    function title_display($rec)
    {
      return $rec["title"]."------";
    }

    function adminFooter()
    {
      return nodeSourceUrl("lesson7.category");
    }
  }

?>