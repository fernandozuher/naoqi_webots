<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
		xmlns="http://www.w3.org/1999/xhtml"
		version="1.0">

  <xsl:output method="xml" encoding="utf-8"
	      doctype-system="http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd"
	      doctype-public="-//W3C//DTD XHTML 1.0 Strict//EN"/>


  <xsl:template match="/article|/book" mode="toc">
    <div id="toc">
      <div class="tocpart tochead">
	<h2 title="{title}"><xsl:value-of select="title"/></h2>
      </div>
      <div id="toccontent">
	<xsl:apply-templates select="section" mode="toc"/>
      </div>
    </div>
  </xsl:template>

  <xsl:template match="section[section]" mode="toc">
    <div class="tocpart expandable" id="m_{generate-id()}">
      <span  onclick="toc_toggle('{generate-id()}')">
	<span class="toggle" id="expand_{generate-id()}">&gt;</span>
	<span class="reduce toggle" id="reduce_{generate-id()}">v</span>
	<a href="#{generate-id()}"><xsl:value-of select="title"/></a>
      </span>
      <div class="tocsubpart" id="l_{generate-id()}">
	<ul>
	  <xsl:apply-templates select="section" mode="subtoc"/>
	</ul>
      </div>
    </div>
  </xsl:template>

  <xsl:template match="section" mode="toc">
    <div class="tocpart simple" id="m_{generate-id()}">
      <a href="#{generate-id()}"><xsl:value-of select="title"/></a>
    </div>
  </xsl:template>

  <xsl:template match="section" mode="subtoc">
    <li>
      <a href="#{generate-id()}"><xsl:value-of select="title"/></a>
      <xsl:if test="section">
	<ul>
	  <xsl:apply-templates select="section" mode="subtoc"/>
	</ul>
      </xsl:if>
    </li>
  </xsl:template>


</xsl:stylesheet>
