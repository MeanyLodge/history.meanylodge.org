---
title: Committee
category: List
---
# Committee
### Official List

- [Google Doc](https://docs.google.com/spreadsheets/d/1to29Ygj0r_x5WCVPrw_nrgDNCTNY6K2Xok4pdhTFeas/edit#gid=1586101550)

### Members

<ul>
  {% for doc in site.pages %}
    {% if doc.category == "Person" %}
      {% if doc.categories contains "Committee" %}
  <li><a href="/History{{ doc.url }}">{{ doc.title }}</a></li>
      {% endif %}
    {% endif %}
  {% endfor %}
</ul>

###### The above list is generated from front matter. If 'Committee' is in the `categories` field, the Person will appear in the list.