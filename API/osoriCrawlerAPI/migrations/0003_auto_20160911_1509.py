# -*- coding: utf-8 -*-
# Generated by Django 1.10 on 2016-09-11 06:09
from __future__ import unicode_literals

from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('osoriCrawlerAPI', '0002_auto_20160911_1508'),
    ]

    operations = [
        migrations.AlterField(
            model_name='crawler',
            name='crawler_id',
            field=models.CharField(max_length=100, unique=True),
        ),
    ]
