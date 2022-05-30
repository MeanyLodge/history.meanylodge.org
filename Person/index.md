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

* [Chair](/Person/Chair)
* [Committee](/Person/Committee)
* [Cook](/Person/Cook)
* [Driver](/Person/Driver)
* [Fossil](/Person/Fossil)
* [Historian](/Person/Historian)
* Ski [Instructor](/Person/Instructor)
* [Mechanic](/Person/Mechanic)
* Tow [Operator](/Person/Operator)
* [Permanent Resident](/Person/Permanent-Resident)


###### [template](/Person/Template)
