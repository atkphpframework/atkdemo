<?PHP

/**
   * This node demonstrates 'row based data internationalisation'.
   *
   * This node is very similar to the translation node (read the
   * documentation over there first).
   *
   * The difference is in storage. With row based data
   * internationalisation, there aren't multiple columns as in the
   * previous example. Instead, multiple records are inserted, each
   * for a different language. This requires the addition of one extra
   * column, for example 'language', that stores the language of the
   * row in question.
   *
   * While editing, ATK retrieves all records that belong together to
   * present them in the same interface as with column based i18n.
   * So for the user, both methods look similar. From a database point of
   * view they are entirely different.
   *
   */

  useattrib("atkmlattribute");
  useattrib("atkmltextattribute");
  useattrib("atkmlnumberattribute");
  useattrib("atkmlhtmlattribute");
  useattrib("atkmlselectorattribute");

  class translation_mr extends atkNode
  {
    function translation_mr()
    {
      /**
       * To tell ATK that we want to use row based internationalisation
       * instead of column based, we have to pass the NF_ML flag to the
       * node
       */
      $this->atkNode("translation_mr", NF_ADD_LINK|NF_ML);

      $this->add(new atkAttribute("id", AF_AUTOKEY));
      $this->add(new atkMlSelectorAttribute("mlselect"));
      $this->add(new atkMlAttribute("name", AF_SEARCHABLE));
      $this->add(new atkMlNumberAttribute("numbervalue"));
      $this->add(new atkMlTextAttribute("notes", AF_HIDE_LIST));
      $this->add(new atkMlHtmlAttribute("htmlnotes",AF_HIDE_LIST));

      /**
       * Also, we have to add the language column. It doesn't really matter
       * what you name this column, but you have to add the AF_MULTILANGUAGE
       * flag to tell ATK that this is the column that you use to filter
       * for languages. It can be hidden as the user will not have any use
       * for this column as ATK will present the user with all languages of
       * the same record.
       */
      $this->add(New atkAttribute("lng",AF_MULTILANGUAGE|AF_HIDE));

      $this->setOrder("name");
      $this->setIndex("name");
      $this->setTable("lesson7_translation_mr");
    }

    function descriptor_def()
    {
      return "[name]";
    }

    function adminFooter()
    {
      return nodeSourceUrl("lesson7.translation_mr");;
    }
  }
?>