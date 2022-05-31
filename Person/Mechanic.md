---
title: Mechanic
category: List
---
# Mechanic

Those who regularly work on Meany animals.

### Active Mechanics
<ul>
  {% for doc in site.pages %}
    {% if doc.category == "Person" %}
      {% if doc.categories contains "Mechanic" and doc.categories contains "Active" %}
  <li><a href="{{ doc.url }}">{{ doc.title }}</a></li>
      {% endif %}
    {% endif %}
  {% endfor %}
</ul>

### Past Mechanics
<ul>
  {% for doc in site.pages %}
    {% if doc.category == "Person" and doc.categories contains "Mechanic" %}
      {% unless doc.categories contains "Active" %}
  <li><a href="{{ doc.url }}">{{ doc.title }}</a></li>
      {% endunless %}
    {% endif %}
  {% endfor %}
</ul>

###### this list is incomplete. Send updates to [Matt Simerson](/Person/Matt-Simerson)