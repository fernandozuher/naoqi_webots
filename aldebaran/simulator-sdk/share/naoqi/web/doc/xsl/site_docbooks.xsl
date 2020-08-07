<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
		xmlns="http://www.w3.org/1999/xhtml"
		version="1.0">

  <xsl:output method="text" encoding="utf-8"/>

  <xsl:template match="file">
    <xsl:value-of  select="@name"/>

    <xsl:text>&#x0A;</xsl:text>
  </xsl:template>

  <xsl:template match="text()"/>
</xsl:stylesheet>
