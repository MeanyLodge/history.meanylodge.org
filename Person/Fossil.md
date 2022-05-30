---
title: Fossil
category: List
---
# Fossil

Fossils of Meany

The self-named fossils are a group of Meany elders that embody much of our institutional knowledge. They meet on the first Tuesday of every month for a luncheon. The Meany Elders often tackle big infrastructure projects.

<ul>
  {% for doc in site.pages %}
    {% if doc.category == "Person" %}
      {% if doc.categories contains "Fossil" %}
  <li><a href="{{ doc.url }}">{{ doc.title }}</a></li>
      {% endif %}
    {% endif %}
  {% endfor %}
</ul>