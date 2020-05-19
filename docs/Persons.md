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
      <li><a href="/History{{ doc.url }}">{{ doc.title }}</a></li>
    {% endif %}
  {% endfor %}
</ul>



##### Template

Follow this template for organizating a person page:

- Names
- Events
    - Birth (year only for living persons)
    - Meany Since: YYYY
    - Death (if applicable)
- Roles
- Known For
- More Info
- See Also
- History

If those sections are missing from a person please add it and cite the source. If the source is personal knowledge, tag it with your name. Or send it to Matt-Simerson to post.