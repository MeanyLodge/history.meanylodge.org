---
title: Persons
category: List
---
# Persons
### Lists / Roles

* [Chair](Chair)
* [Committee](Committee)
* [Cook](Cook)
* [Driver](Driver)
* [Historian](Historian)
* [Instructor](Instructor)
* [Mechanic](Mechanic)
* [Permanent Resident](Permanent-Resident)
* Ski [Instructor](Instructor)
* Tow [Operator](Operator)

### Persons

<ul>
  {% for doc in site.pages %}
    {% if doc.category == "Person" %}
      <li><a href="{{ doc.url }}">{{ doc.title }}</a></li>
    {% endif %}
  {% endfor %}
</ul>


###### [template](Person-Template)
