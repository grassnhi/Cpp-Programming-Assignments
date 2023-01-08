this => pointer => recent object

this => have the address of that object

(*this) => == object

    this->attribute_name 
<=> (*this).attribute_name => attribute of recent object

method_name(*this) => method call the recent object

// Local variable and local scope

    class_name::attribute_name
<=> this->attribute_name
<=> (*this).attribute_name
