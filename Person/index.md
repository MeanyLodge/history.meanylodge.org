---
title: Persons
category: List
---

<div style="width: 60%; float: right; text-align: center;">
  <h3>Persons</h3>
  <div style="text-align: left; column-count: 2;">
    <ul style="list-style: none;">
  {% assign persons = site.pages | where: doc.category, "Person" | sort: "title" %}
  {% for doc in persons %}
    {% if doc.category == "Person" %}
      <li><a href="{{ doc.url }}">{{ doc.title }}</a></li>
    {% endif %}
  {% endfor %}
    </ul>
  </div>
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
