---
title: Persons
category: List
---

<div style="width: 45%; float: right; text-align: left;">
<h3>Persons</h3>
<ul style="list-style: none;">
  {% for doc in site.pages %}
    {% if doc.category == "Person" %}
      <li><a href="{{ doc.url }}">{{ doc.title }}</a></li>
    {% endif %}
  {% endfor %}
</ul>
</div>

### Lists / Roles

* [Chair](Chair)
* [Committee](Committee)
* [Cook](Cook)
* [Driver](Driver)
* [Fossil](Fossil)
* [Historian](Historian)
* Ski [Instructor](Instructor)
* [Mechanic](Mechanic)
* Tow [Operator](Operator)
* [Permanent Resident](Permanent-Resident)


###### [template](Person-Template)
