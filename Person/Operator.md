---
title: Tow Operators
category: List
---
<img src="img/2020-Operator.jpeg" style="width: 50%;" align="right">
### Tow Operators
<ul>
  {% for doc in site.pages %}
    {% if doc.category == "Person" %}
      {% if doc.categories contains "Operator" and doc.categories contains "Active" %}
  <li><a href="{{ doc.url }}">{{ doc.title }}</a></li>
      {% endif %}
    {% endif %}
  {% endfor %}
</ul>


### Data sources
- [the Google doc](https://docs.google.com/spreadsheets/d/18rj3pNAYnEIen49PyDT2zzw85NiUYV_r3Ec1maQO6ro/edit#gid=0)
- 2019-20 signups
