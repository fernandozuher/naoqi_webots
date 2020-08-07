<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
		xmlns="http://www.w3.org/1999/xhtml"
		version="1.0">

  <xsl:output method="text" encoding="utf-8"/>

  <xsl:template match="modules/module">
    <xsl:apply-templates select="document(href)"/>
  </xsl:template>

  <xsl:template match="specificpage">
    <xsl:value-of select="."/>
    <xsl:text>&#x0A;</xsl:text>
  </xsl:template>

  <xsl:template match="text()"/>

</xsl:stylesheet>
